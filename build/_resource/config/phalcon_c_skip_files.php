<?php
// These are the files that must not be added to phalcon.c
//

$skipFiles = array(
    // Included by phalcon.c header - see phalcon_c_header.php
    'config.h',
    'ext_config.h',
    'php.h',
    'ext.h',
    'php_phalcon.h',
    'phalcon.h',
    'phalcon.c',

    'phalcon/annotations/scanner.h',
    'phalcon/annotations/annot.h',
    'phalcon/mvc/url/utils.h',
    'phalcon/mvc/model/orm.h',
    'phalcon/mvc/model/query/scanner.h',
    'phalcon/mvc/model/query/phql.h',
    'phalcon/mvc/view/engine/volt/scanner.h',
    'phalcon/mvc/view/engine/volt/volt.h',

    'phalcon/annotations/base.c',
    'phalcon/annotations/lempar.c',
    'phalcon/annotations/lemon.c',
    'phalcon/annotations/parser.php5.c',
    'phalcon/annotations/parser.php7.c',

    'phalcon/mvc/view/engine/volt/base.c',
    'phalcon/mvc/view/engine/volt/lempar.c',
    'phalcon/mvc/view/engine/volt/lemon.c',
    'phalcon/mvc/view/engine/volt/parser.php5.c',
    'phalcon/mvc/view/engine/volt/parser.php7.c',

    'phalcon/mvc/model/query/base.c',
    'phalcon/mvc/model/query/lempar.c',
    'phalcon/mvc/model/query/lemon.c',
    'phalcon/mvc/model/query/parser.php5.c',
    'phalcon/mvc/model/query/parser.php7.c',
);

return $skipFiles;
