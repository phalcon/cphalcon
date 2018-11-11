<?php

namespace Helper\Traits;

use Phalcon\Di;
use Phalcon\Escaper;
use Phalcon\Events\Manager;
use Phalcon\Filter;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Mvc\Url;

trait DiTrait
{
    public function setDiUrl()
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
}
