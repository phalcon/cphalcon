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

namespace Phalcon\Test\Unit\Http\Message\InputStream;

use UnitTester;

/**
 * Class GetMetadataCest
 */
class GetMetadataCest
{
    /**
     * Tests Phalcon\Http\Message\InputStream :: getMetadata()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageInputStreamGetMetadata(UnitTester $I)
    {
        $I->wantToTest('Http\Message\InputStream - getMetadata()');
        $I->skipTest('Need implementation');
    }
}
