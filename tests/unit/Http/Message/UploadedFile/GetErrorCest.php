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

namespace Phalcon\Test\Unit\Http\Message\UploadedFile;

use Phalcon\Http\Message\UploadedFile;
use UnitTester;

class GetErrorCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: getError()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileGetError(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - getError()');
        $file = new UploadedFile('php://memory', 100);

        $expected = UPLOAD_ERR_OK;
        $actual   = $file->getError();
        $I->assertEquals($expected, $actual);
    }
}
