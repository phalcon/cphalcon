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
    'assets/filters/jsminifier.h',
    'assets/filters/cssminifier.h',
);
