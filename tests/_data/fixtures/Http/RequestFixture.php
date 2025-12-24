<?php

namespace Phalcon\Tests\Fixtures\Http;

use Phalcon\Http\Request;

class RequestFixture extends Request
{
    public function getTrustedProxies(): array
    {
        return $this->trustedProxies;
    }
}