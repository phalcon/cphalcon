<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class HasFilesCest extends HttpBase
{
    /**
     * Tests Request::hasFiles
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-01-31
     */
    public function testRequestHasFiles(UnitTester $I)
    {
        $store = $_FILES ?? [];

        $request = $this->getRequestObject();
        $_FILES  = [];

        $I->assertFalse(
            $request->hasFiles()
        );

        $_FILES = [
            'test' => [
                'name'     => 'name',
                'type'     => 'text/plain',
                'size'     => 1,
                'tmp_name' => 'tmp_name',
                'error'    => 0,
            ],
        ];

        $I->assertTrue(
            $request->hasFiles()
        );

        $_FILES = $store;
    }
}
