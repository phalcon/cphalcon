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

namespace Phalcon\Test\Unit\Http\Request\File;

use UnitTester;

class GetExtensionCest
{
    /**
     * Tests Phalcon\Http\Request\File :: getExtension()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestFileGetExtension(UnitTester $I)
    {
        $I->wantToTest('Http\Request\File - getExtension()');

        $I->skipTest('Need implementation');
    }
}
