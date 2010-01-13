#!./perl

BEGIN {
    chdir 't';
    @INC = '../lib';
    require './test.pl';
}

plan tests => 26 * 3;

use warnings qw/syntax/;
use version;

# test: package NAME VERSION

my $skip_regex_tests = 0;

while (<DATA>) {
    chomp;
    my ($v, $p, $nq, $n, $match) = split /\t+/;
    if ($v =~ /^#/) {
	diag $v;
	if ($v =~ /trouble/) {
	    $skip_regex_tests = 1;
	}
    }
    my $warning = "";
    local $SIG{__WARN__} = sub { $warning .= $_[0] . "\n" };
    $match = defined $match ? $match : "";

    # First handle the 'package NAME VERSION' case
    $withversion::VERSION = undef;
    if ($p eq 'fail') {
	eval "package withversion $v";
	like($@, qr/$match/, "package withversion $v -> syntax error ($match)");
	ok($v !~ /$version::STRICT/, "Doesn't match STRICT regex") 
	    unless $skip_regex_tests;
    }
    else {
	my $ok = eval "package withversion $v; $v eq \$withversion::VERSION";
	ok($ok, "package withversion $v")
          or diag( $@ ? $@ : "and \$VERSION = $withversion::VERSION");
	ok($v =~ /$version::STRICT/, "Matches STRICT regex")
	    unless $skip_regex_tests;
    }
    

    # Now check the version->new("V") case
    my $ver = undef;
    eval qq/\$ver = version->new("$v")/;
    if ($nq eq 'fail') {
	like($@, qr/$match/, qq{version->new("$v") -> invalid format ($match)})
          or diag( $@ ? $@ : "and \$ver = $ver" );
	ok($v !~ /$version::LAX/, "Doesn't match LAX regex")
	    unless $skip_regex_tests;
    }
    else {
	is($@, "", qq{version->new("$v")});
	ok($v =~ /$version::LAX/, "Matches LAX regex")
	    unless $skip_regex_tests;
    }

    # Now check the version->new(V) case
    $ver = undef; 
    eval qq/\$ver = version->new($v)/;
    if ($nq eq 'fail') {
	like($@, qr/$match/m, qq{version->new($v) -> invalid format ($match)})
          or diag( $@ ? $@ : "and \$ver = $ver" );
    }
    else {
	is($@, "", qq{version->new("$v")});
    }
}


# The data is organized in tab delimited format with these columns:
#
# value		package		version->new	version->new	regex
# 				quoted		unquoted
#
# For each value, it is tested using eval in the following expressions
#
# 	package foo $value;			# column 2
# and 
# 	my $ver = version->new("$value");	# column 3
# and 
# 	my $ver = version->new($value);		# column 4
#
# The second through fourth columns can contain 'pass' or 'fail'.
#
# For any column with 'pass', the tests makes sure that no warning/error
# was thrown.  For any column with 'fail', the tests make sure that the
# error thrown matches the regex in the last column.
#
# If all columns are marked 'pass', the regex column is left empty.
#
# If the DATA line begins with a # mark, it is used as a diag comment and
# may also have side effects in the test (see the "Total garbage" block)
__DATA__
1.00		pass	pass	pass
1.00001		pass	pass	pass
0.123		pass	pass	pass
12.345		pass	pass	pass
42		pass	pass	pass
0		pass	pass	pass
0.0		pass	pass	pass
01		fail	pass	pass	no leading zeros
01.0203		fail	pass	pass	no leading zeros
1.		fail	pass	pass	1.\[0-9] required
.1		fail	pass	pass	0 before decimal required
v1.2.3		pass	pass	pass
v1.2		fail	pass	pass	dotted-decimal versions require at least three parts
v1.2.3.4	pass	pass	pass
1.2.3		fail	pass	pass	dotted-decimal versions require at least three parts
v0.1.2		pass	pass	pass
v0.0.0		pass	pass	pass
v1		fail	pass	pass	dotted-decimal versions require at least three parts
v01		fail	pass	pass	no leading zeros
v01.02.03	fail	pass	pass	no leading zeros
v.1.2.3		fail	fail	fail	dotted-decimal versions require at least three parts
v1.2345.6	fail	pass	pass	maximum 3 digits between decimals
bar		fail	fail	fail	version required
1a		fail	fail	fail	1.\[0-9] required
v		fail	fail	fail	dotted-decimal versions require at least three parts
$foo		fail	fail	fail	version required
