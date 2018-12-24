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

namespace Phalcon\Test\Integration\Forms\Element\Email;

use IntegrationTester;

/**
 * Class GetFiltersCest
 */
class GetFiltersCest
{
    /**
     * Tests Phalcon\Forms\Element\Email :: getFilters()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementEmailGetFilters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Email - getFilters()');
        $I->skipTest('Need implementation');
    }
}
