<?php

/**
 * Fixture for Compiler test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\View\Engine\Volt
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

return [
    [
        [
            'removeFiles' => [
                PATH_DATA . 'views/test10/children2.volt.php',
                PATH_DATA . 'views/test10/parent.volt%%e%%.php',
            ],
            'compileFile' => PATH_DATA . 'views/test10/children2.volt',
            'contentPath' => PATH_DATA . 'views/test10/children2.volt.php',
        ],
        '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN"><html lang="en"><html xmlns="http://www.w3.org/1999/xhtml"><head><style type="text/css">.important { color: #336699; } </style> <link rel="stylesheet" href="style.css" /> <title>Index - My Webpage</title></head><body><div id="content"><h1>Index</h1><p class="important">Welcome to my awesome homepage.</p></div><div id="footer">&copy; Copyright 2012 by <a href="http://domain.invalid/">you</a>.</div></body>',
    ],
];
