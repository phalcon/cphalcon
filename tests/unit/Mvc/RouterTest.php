<?php

namespace Phalcon\Test\Unit\Mvc;

use UnitTester;
use Phalcon\Test\Module\UnitTest;

class RouterTest extends UnitTest
{
    public function test(UnitTester $I)
    {
        $I->wantTo('test something');
    }
}
