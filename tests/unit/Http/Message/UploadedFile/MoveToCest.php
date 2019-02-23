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
 * Class MoveToCest
 */
class MoveToCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileMoveTo(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo()');
        $source = $I->getNewFileName();
        $source = outputFolder('tests/stream/' . $source);
        $stream = new Stream($source, 'w+b');
        $stream->write('Phalcon Framework');

        $file   = new UploadedFile($stream, 0);
        $target = $I->getNewFileName();
        $target = outputFolder('tests/stream/' . $target);

        $file->moveTo($target);

        $actual = file_exists($target);
        $I->assertTrue($actual);

        $expected = (string) $stream;
        $actual   = file_get_contents($target);
        $I->assertEquals($expected, $actual);
    }
}
