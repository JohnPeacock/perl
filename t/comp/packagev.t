#!./perl

BEGIN {
    chdir 't';
    @INC = '../lib';
    require './test.pl';
}

my @lines = <DATA>;
my $count = grep { $_ !~ /^#/ } @lines;

plan tests => $count * 5;

use warnings qw/syntax/;
use version;

# test: package NAME VERSION

my $skip_regex_tests = 0;

LINE:
for (@lines) {
    chomp;
    my ($v, $p, $nq, $n, $match) = split /\t+/;
    # comments in data section are just diagnostics
    if ($v =~ /^#/) {
	diag $v;
        next LINE;
    }
    my $warning = "";
    local $SIG{__WARN__} = sub { $warning .= $_[0] . "\n" };
    $match = defined $match ? $match : "";

    # First handle the 'package NAME VERSION' case
    $withversion::VERSION = undef;
    if ($p eq 'fail') {
	eval "package withversion $v";
	like($@, qr/$match/, "package withversion $v -> syntax error ($match)");
	unlike($v, $version::STRICT_Az, qq{... and "$v" should also fail STRICT regex});
    }
    else {
	my $ok = eval "package withversion $v; $v eq \$withversion::VERSION";
	ok($ok, "package withversion $v")
          or diag( $@ ? $@ : "and \$VERSION = $withversion::VERSION");
	like($v, $version::STRICT_Az, qq{... and "$v" should pass STRICT regex});
    }
    

    # Now check the version->new("V") case
    my $ver = undef;
    eval qq/\$ver = version->new("$v")/;
    if ($nq eq 'fail') {
	like($@, qr/$match/, qq{version->new("$v") -> invalid format ($match)})
          or diag( $@ ? $@ : "and \$ver = $ver" );
	unlike($v, $version::LAX_Az, qq{... and "$v" should fail LAX regex});
    }
    else {
	is($@, "", qq{version->new("$v")});
	like($v, $version::LAX_Az, qq{... and "$v" should pass LAX regex});
    }

    # Now check the version->new(V) case
    $ver = undef; 
    eval qq/\$ver = version->new($v)/;
    if ($n eq 'fail') {
	like($@, qr/$match/m, qq{... and unquoted version->new($v) has same error})
          or diag( $@ ? $@ : "and \$ver = $ver" );
    }
    elsif ($n eq 'pass') {
	is($@, "", qq{... and version->new($v) is ok});
    }
    else {
        pass( "... skipping version->new($v)" );
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
# error thrown matches the regex in the last column.  The unquoted column
# may also have 'na' indicating that it's pointless to test as behavior
# is subject to the perl parser before a stringifiable value is available
# to version->new
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
v1.2.3		pass	pass	pass
v1.2.3.4	pass	pass	pass
v0.1.2		pass	pass	pass
v0.0.0		pass	pass	pass
01		fail	pass	pass	no leading zeros
01.0203		fail	pass	pass	no leading zeros
v01		fail	pass	pass	no leading zeros
v01.02.03	fail	pass	pass	no leading zeros
1.		fail	pass	pass	1.\[0-9] required
.1		fail	pass	pass	0 before decimal required
1.02_03		fail	pass	pass	underscores
1.2_3.4		fail	fail	fail	underscores
v1.2_3		fail	pass	pass	underscores
1.02_03_04	fail	fail	na	underscores
v1.02_03	fail	pass	pass	underscores
v1.2_3_4	fail	fail	fail	underscores
v1.2		fail	pass	pass	dotted-decimal versions require at least three parts
v1		fail	pass	pass	dotted-decimal versions require at least three parts
v.1.2.3		fail	fail	fail	dotted-decimal versions require at least three parts
1.2.3		fail	pass	pass	dotted-decimal versions require at least three parts
v		fail	fail	fail	dotted-decimal versions require at least three parts
v1.2345.6	fail	pass	pass	maximum 3 digits between decimals
bar		fail	fail	na	version required
1a		fail	fail	na	1.\[0-9] required
