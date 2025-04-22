<?php

namespace Phalcon\Tests\Fixtures\Mvc;

class Router extends \Phalcon\Mvc\Router
{
    public function protectedExtractRealUri($uri)
    {
        return parent::extractRealUri($uri);
    }
}