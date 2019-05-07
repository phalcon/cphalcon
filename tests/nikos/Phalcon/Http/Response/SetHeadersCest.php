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

namespace Phalcon\Test\Unit\Http\Response;

use UnitTester;

class SetHeadersCest
{
    /**
     * Tests Phalcon\Http\Response :: setHeaders()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpResponseSetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Response - setHeaders()');

        $I->skipTest('Need implementation');
    }
}
