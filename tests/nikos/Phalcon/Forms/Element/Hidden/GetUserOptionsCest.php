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

namespace Phalcon\Test\Unit\Forms\Element\Hidden;

use UnitTester;

class GetUserOptionsCest
{
    /**
     * Tests Phalcon\Forms\Element\Hidden :: getUserOptions()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function formsElementHiddenGetUserOptions(UnitTester $I)
    {
        $I->wantToTest('Forms\Element\Hidden - getUserOptions()');

        $I->skipTest('Need implementation');
    }
}
