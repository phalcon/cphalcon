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

use Phalcon\Http\Request;
use UnitTester;

class GetUploadedFilesCest
{
    /**
     * Tests Phalcon\Http\Request :: getUploadedFiles()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetUploadedFiles(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getUploadedFiles()');

        $store  = $_FILES ?? [];
        $_FILES = [
            'test' => [
                'name'     => 'name',
                'type'     => 'text/plain',
                'size'     => 1,
                'tmp_name' => 'tmp_name',
                'error'    => 0,
            ],
        ];

        $request = new Request();

        $actual = $request->getUploadedFiles();
        $I->assertInstanceOf(Request\File::class, $actual[0]);

        $_FILES = $store;
    }
}
