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

class GetClientFilenameCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: getClientFilename()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileGetClientFilename(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - getClientFilename()');
        $file = new UploadedFile(
            'php://memory',
            0,
            UPLOAD_ERR_OK,
            'phalcon.txt'
        );

        $expected = 'phalcon.txt';
        $actual   = $file->getClientFilename();
        $I->assertEquals($expected, $actual);
    }
}
