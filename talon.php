<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

/*
 * Suite map for the talon test runner: every suite loads the locally built
 * extension, so `talon run <suite>` replaces the hand-composed
 * `php -d extension=... vendor/bin/phpunit -c resources/phpunit.<suite>.xml`.
 */
return [
    'php'     => ['extension=ext/modules/phalcon.so'],
    'suites'  => [
        'unit'   => ['config' => 'resources/phpunit.xml.dist'],
        'mysql'  => ['config' => 'resources/phpunit.mysql.xml'],
        'pgsql'  => ['config' => 'resources/phpunit.pgsql.xml'],
        'sqlite' => ['config' => 'resources/phpunit.sqlite.xml'],
    ],
    'default' => 'unit',
];
