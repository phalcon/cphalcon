<?php
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
