<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\UploadedFile;

use Phalcon\Http\Message\UploadedFile;
use UnitTester;

class GetSizeCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: getSize()
     *
     * @since  2019-02-10
     */
    public function httpMessageUploadedFileGetSize(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - getSize()');
        $file = new UploadedFile('php://memory', 100);

        $expected = 100;
        $actual   = $file->getSize();
        $I->assertEquals($expected, $actual);
    }
}
