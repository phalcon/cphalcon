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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use UnitTester;

/**
 * Class GetUploadedFilesCest
 */
class GetUploadedFilesCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getUploadedFiles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-08
     */
    public function httpMessageServerRequestGetUploadedFiles(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getUploadedFiles()');
        $I->skipTest('Need implementation');
    }
}
