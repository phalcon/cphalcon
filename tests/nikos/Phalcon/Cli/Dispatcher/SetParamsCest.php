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

namespace Phalcon\Test\Unit\Cli\Dispatcher;

use UnitTester;

/**
 * Class SetParamsCest
 */
class SetParamsCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setParams()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function cliDispatcherSetParams(UnitTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setParams()');
        $I->skipTest('Need implementation');
    }
}
