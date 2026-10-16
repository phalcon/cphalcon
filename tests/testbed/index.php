<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

use Phalcon\Debug;
use Phalcon\Di\FactoryDefault;
use Phalcon\Tag;

$_ENV['APP_DEBUG'] = true;

$debug = new Debug();

$debug->setBlacklist(
    [
        'request' => ['some'],
        'server'  => ['hostname'],
    ]
);

$debug->listen();

$container = new FactoryDefault();

$x = new C();

$x->rump();


class C
{
    public function rump()
    {
        $return = Tag::displayTo(false, true);
    }
}
