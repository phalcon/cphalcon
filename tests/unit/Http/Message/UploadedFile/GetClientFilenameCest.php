<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\UploadedFile;

use Phalcon\Http\Message\UploadedFile;
use UnitTester;

/**
 * Class GetClientFilenameCest
 */
class GetClientFilenameCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: getClientFilename()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
