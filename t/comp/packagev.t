#!./perl

BEGIN {
    chdir 't';
    @INC = '../lib';
    require './test.pl';
}

plan tests => 125;

use warnings qw/syntax/;
# test: package NAME VERSION

while (<DATA>) {
    chomp;
    my ($v, $p, $nq, $n, $match) = split /\t+/;
    my $warning = "";
    local $SIG{__WARN__} = sub { $warning .= $_[0] . "\n" };

    # First handle the 'package NAME VERSION' case
    if ($p eq 'fail') {
	eval "package withversion $v";
	like($@, qr/$match/, "package withversion $v -> syntax error");
    }
    else {
	my $ok = eval "package withversion $v; $v eq \$withversion::VERSION";
	ok($ok, "package withversion $v");
    }
    

    # Now check the version->new("V") case
    my $ver;
    eval qq/\$ver = version->new("$v")/;
    if ($nq eq 'fail') {
	like($@, qr/$match/, "Invalid version format ($match)");
    }
    else {
	isnt($@, qq/version->new("$v") $match/);
    }

    # Now check the version->new(V) case
    my $ver;
    eval qq/\$ver = version->new($v)/;
    if ($nq eq 'fail') {
	like($@, qr/$match/m, "Invalid version format ($match)");
    }
    else {
	isnt($@, qq/version->new("$v") $match/);
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
__DATA__
1.00		pass	pass	pass
1.00001		pass	pass	pass
0.123		pass	pass	pass
12.345		pass	pass	pass
01		fail	pass	pass	no leading zeros
01.0203		fail	pass	pass	no leading zeros
1.		fail	pass	pass	1.\[0-9] required
.1		fail	pass	pass	0 before decimal required
Bar		fail	fail	fail	version required
1a		fail	fail	fail	1.\[0-9] required
v		fail	fail	fail	dotted-decimal versions require at least three parts
$foo		fail	fail	fail	version required
v1.2.3		pass	pass	pass
v1.2		fail	pass	pass	dotted-decimal versions require at least three parts
v1.2.3.4	pass	pass	pass
1.2.3		fail	pass	pass	dotted-decimal versions require at least three parts
v0.1.2		pass	pass	pass
v1		fail	pass	pass	dotted-decimal versions require at least three parts
v01		fail	pass	pass	no leading zeros
v01.02.03	fail	pass	pass	no leading zeros
v.1.2.3		fail	fail	fail	dotted-decimal versions require at least three parts
v1.2345.6	fail	pass	pass	maximum 3 digits between decimals
