#!./perl

BEGIN {
    chdir 't';
    @INC = '../lib';
    require './test.pl';
}

plan tests => 22;

use warnings qw/syntax/;
# test: package NAME VERSION

while (<DATA>) {
    chomp;
    my ($v, $expected, $match) = split /\t+/;
    if ($expected eq 'fail') {
	no warnings 'reserved';
	eval "package withversion $v";
	like($@, qr/$match/m, "package withversion $v -> syntax error ($match)");
    }
    elsif ($expected eq 'pass') {
	my $ok = eval "package withversion $v; $v eq \$withversion::VERSION";
	ok($ok, "package withversion $v");
    }
}

__DATA__
1.00		pass
1.00001		pass
0.123		pass
12.345		pass
01		fail	no leading zeros
01.0203		fail	no leading zeros
1.		fail	1.\[0-9] required
.1		fail	0 before decimal required
Bar		fail	version required
1a		fail	1.\[0-9] required
v		fail	dotted-decimal versions require at least three parts
$foo		fail	version required
v1.2.3		pass
v1.2		fail	dotted-decimal versions require at least three parts
v1.2.3.4	pass
1.2.3		fail	dotted-decimal versions require at least three parts
v0.1.2		pass
v1		fail	dotted-decimal versions require at least three parts
v01		fail	no leading zeros
v01.02.03	fail	no leading zeros
v.1.2.3		fail	dotted-decimal versions require at least three parts
v1.2345.6	fail	maximum 3 digits between decimals
