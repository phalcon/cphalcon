<?php
// These are the files that must not be added to phalcon.c

return array(
    // Included by phalcon.c header - see phalcon_c_header.php
    'config.h',
    'php.h',
    'php_phalcon.h',
    'phalcon.h',
    // Already a part of parser.c files (appended to parser.c upon compiler recompilation)
    'annotations/base.c',
    'mvc/model/query/base.c',
    'mvc/view/engine/volt/base.c',
    // Placeholders for non-free minifiers
    'assets/filters/nojsminifier.h',
    'assets/filters/nojsminifier.c',
    'assets/filters/nocssminifier.h',
    'assets/filters/nocssminifier.c',
);
