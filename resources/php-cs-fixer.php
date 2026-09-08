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

use Phalcon\CodeQuality\PhpCsFixer\ConfigFactory;

$root = dirname(__DIR__);

return ConfigFactory::create(
    [
        $root . '/tests/unit',
        $root . '/tests/database',
    ],
    $root . '/tests/_output/.php-cs-fixer.cache'
);
