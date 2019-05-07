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

namespace Phalcon\Test\Unit\Http\Request\File;

use UnitTester;

class GetExtensionCest
{
    /**
     * Tests Phalcon\Http\Request\File :: getExtension()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpRequestFileGetExtension(UnitTester $I)
    {
        $I->wantToTest('Http\Request\File - getExtension()');

        $I->skipTest('Need implementation');
    }
}
