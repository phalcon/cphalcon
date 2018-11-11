<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Crypt;
use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Events\Manager;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Session\Adapter\Files as FilesSession;
use Phalcon\Mvc\Url;

trait DiTrait
{
    protected function getDi()
    {
        return Di::getDefault();
    }

    protected function newDi()
    {
        Di::reset();
        $container = new Di();
        Di::setDefault($container);
    }

    protected function resetDi()
    {
        Di::reset();
    }

    protected function setDiCrypt()
    {
        $container = Di::getDefault();
        $container->set(
            'crypt',
            function () {
                $crypt = new Crypt();
                $crypt->setKey('cryptkeycryptkey');

                return $crypt;
            }
        );
    }

    protected function setDiEscaper()
    {
        $container = Di::getDefault();
        $container->setShared('escaper', Escaper::class);
    }

    protected function setDiEventsManager()
    {
        $container = Di::getDefault();
        $container->setShared('eventsManager', Manager::class);
    }

    protected function setDiFilter()
    {
        $container = Di::getDefault();
        $container->setShared('filter', Filter::class);
    }

    protected function setDiResponse()
    {
        $container = Di::getDefault();
        $container->set('response', Response::class);
    }

    protected function setDiRequest()
    {
        $container = Di::getDefault();
        $container->set('request', Request::class);
    }

    protected function setDiSession()
    {
        $container = Di::getDefault();
        $container->setShared('session', FilesSession::class);
    }

    protected function setDiUrl()
    {
        $container = Di::getDefault();
        $container->setShared(
            'url',
            function () {
                $url = new Url();
                $url->setBaseUri('/');

                return $url;
            }
        );
    }
}
