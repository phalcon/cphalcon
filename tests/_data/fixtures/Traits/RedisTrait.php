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

use UnitTester;

trait RedisTrait
{
    protected $options = [];

    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('redis');
        $this->options = [
            'host'     => env('TEST_RS_HOST'),
            'port'     => env('TEST_RS_PORT'),
            'index'    => env('TEST_RS_DB'),
            'statsKey' => '_PHCR',
        ];
    }
}
