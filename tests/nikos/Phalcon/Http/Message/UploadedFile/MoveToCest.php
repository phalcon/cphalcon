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

use UnitTester;

class MoveToCest
{
    /**
     * Tests Phalcon\Http\Message\UploadedFile :: moveTo()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpMessageUploadedFileMoveTo(UnitTester $I)
    {
        $I->wantToTest('Http\Message\UploadedFile - moveTo()');

        $I->skipTest('Need implementation');
    }
}
