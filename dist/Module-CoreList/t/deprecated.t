#!perl -w
use strict;
use Test::More tests => 7;

require_ok('Module::CoreList');

ok($Module::CoreList::deprecated{5.011000},    "5.011000 (deprecated list)");

ok(!exists $Module::CoreList::deprecated{5.011000}{'File::Spec'},
   "File::Spec not deprecated in 5.011000 (hash)"
);

ok(! Module::CoreList->is_deprecated('File::Spec'),
   "File::Spec not deprecated in 5.011000 (method)"
);

ok(exists $Module::CoreList::deprecated{5.011000}{'Switch'},
   "Switch deprecated in 5.011000 (hash)"
);

ok(Module::CoreList->is_deprecated('Switch'),
   "Switch deprecated in 5.011000 (method)"
);

ok(! Module::CoreList->is_deprecated('Switch', 5.010), 
   "Switch not deprecated in 5.010 (method w/ perl version)"
);

