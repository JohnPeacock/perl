#!perl -w
package version;

use 5.005_04;
use strict;

use vars qw(@ISA $VERSION $CLASS $STRICT $LAX $STRICT_Az $LAX_Az *declare *qv);

$VERSION = 0.81;

$CLASS = 'version';

# First part of either decimal or dotted-decimal version number.  Unsigned
# integer with no leading zeroes (except for zero itself) to avoid
# confusion with octal.
my $INTEGER_PART = qr/0|[1-9][0-9]*/;

# Fraction part of a decimal version number.
my $FRACTION_PART = qr/\.[0-9]+/;

# Strict decimal version number.
my $STRICT_DECIMAL_VERSION = qr/ $INTEGER_PART $FRACTION_PART? /x;

# Second and subsequent part of a strict dotted-decimal version number.  Leading
# zeroes are permitted, and the number is always decimal.  Limited to
# three digits to avoid overflow when converting to decimal form and
# also avoid problematic style with excessive leading zeroes.
my $STRICT_DOTTED_DECIMAL_PART = qr/\.[0-9]{1,3}/;

# Strict dotted-decimal version number.  Must have both leading "v" and at least
# three parts, to avoid confusion with decimal syntax.
my $STRICT_DOTTED_DECIMAL_VERSION = qr/ v $INTEGER_PART $STRICT_DOTTED_DECIMAL_PART{2,} /x;

# Complete strict version number syntax.
$STRICT =
	qr/ $STRICT_DECIMAL_VERSION | $STRICT_DOTTED_DECIMAL_VERSION /x;
$STRICT_Az = qr/ \A $STRICT \z /x;

# Alpha suffix part of lax version number syntax.  Acts like a dotted-decimal
# part.
my $LAX_ALPHA_PART = qr/_[0-9]+/;

# Lax decimal version number.  Just like the strict one except for
# allowing an alpha suffix.
my $LAX_DECIMAL_VERSION =
	qr/ $INTEGER_PART (?: $FRACTION_PART $LAX_ALPHA_PART? )? /x;

# Second and subsequent part of a lax dotted-decimal version number.  Leading
# zeroes are permitted, and the number is always decimal.  No limit on
# the numerical value or number of digits, so there is the possibility
# of overflow when converting to decimal form.
my $LAX_DOTTED_DECIMAL_PART = qr/\.[0-9]+/;

# Lax dotted-decimal version number.  Distinguished by having either leading
# "v" or at least three non-alpha parts.  Alpha part is only permitted
# if there are at least two non-alpha parts.
my $LAX_DOTTED_DECIMAL_VERSION = qr/
	v $INTEGER_PART (?: $LAX_DOTTED_DECIMAL_PART+ $LAX_ALPHA_PART? )?
	|
	$INTEGER_PART $LAX_DOTTED_DECIMAL_PART{2,} $LAX_ALPHA_PART?
/x;

# Complete lax version number syntax.
$LAX = qr/ $LAX_DECIMAL_VERSION | $LAX_DOTTED_DECIMAL_VERSION /x;
$LAX_Az = qr/ \A $LAX \z /x;

# Preloaded methods go here.
sub import {
    no strict 'refs';
    my ($class) = shift;

    # Set up any derived class
    unless ($class eq 'version') {
	local $^W;
	*{$class.'::declare'} =  \&version::declare;
	*{$class.'::qv'} = \&version::qv;
    }

    my %args;
    if (@_) { # any remaining terms are arguments
	map { $args{$_} = 1 } @_
    }
    else { # no parameters at all on use line
    	%args = 
	(
	    qv => 1,
	    'UNIVERSAL::VERSION' => 1,
	);
    }

    my $callpkg = caller();
    
    if (exists($args{declare})) {
	*{$callpkg."::declare"} = 
	    sub {return $class->declare(shift) }
	  unless defined(&{$callpkg.'::declare'});
    }

    if (exists($args{qv})) {
	*{$callpkg."::qv"} =
	    sub {return $class->qv(shift) }
	  unless defined(&{"$callpkg\::qv"});
    }

    if (exists($args{'VERSION'})) {
	*{$callpkg."::VERSION"} = \&version::_VERSION;
    }
}

1;
