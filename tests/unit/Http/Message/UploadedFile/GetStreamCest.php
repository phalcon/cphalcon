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

use Phalcon\Http\Message\Stream;
use Phalcon\Http\Message\UploadedFile;
use UnitTester;

/**
 * Class GetStreamCest
 */
class GetStreamCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: getStream()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileGetStream(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - getStream()');
        $stream = new Stream('php://memory');
        $file   = new UploadedFile(
            $stream,
            0,
            UPLOAD_ERR_OK,
            'phalcon.txt'
        );

        $expected = $stream;
        $actual   = $file->getStream();
        $I->assertEquals($expected, $actual);
    }
}
