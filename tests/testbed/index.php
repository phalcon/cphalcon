<?php
declare(strict_types=1);

use Phalcon\Debug;
use Phalcon\Exception;
use Phalcon\Di\FactoryDefault;

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
    function rump()
    {
        $return = \Phalcon\Tag::displayTo(false, true);
    }
}

