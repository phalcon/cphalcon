<?php

namespace Helper\Traits;

use Phalcon\Di;
use Phalcon\Escaper;
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
        $container->setShared('escaper', new Escaper());
    }
}
