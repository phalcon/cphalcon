<?php
// These are the files that must not be added to phalcon.c

return array(
    // Included by phalcon.c header - see phalcon_c_header.php
    'config.h',
    'ext_config.h',
    'php.h',
    'ext.h',
    'php_phalcon.h',
    'phalcon.h',
    // Already a part of parser.c files (appended to parser.c upon compiler recompilation)
    'phalcon/annotations/base.c',
    'phalcon/mvc/model/query/base.c',
    'phalcon/mvc/view/engine/volt/base.c',
    'phalcon/assets/filters/jsminifier.h',
    'phalcon/assets/filters/cssminifier.h',
    'phalcon/annotations/lempar.c',
    'phalcon/mvc/model/query/lempar.c',
    'phalcon/mvc/view/engine/volt/lempar.c',
    'phalcon/annotations/lemon.c',
    'phalcon/mvc/model/query/lemon.c',
    'phalcon/mvc/view/engine/volt/lemon.c'
);
