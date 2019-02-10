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

namespace Phalcon\Test\Unit\Escaper;

use UnitTester;

/**
 * Class SetHtmlQuoteTypeCest
 */
class SetHtmlQuoteTypeCest
{
    /**
     * Tests Phalcon\Escaper :: setHtmlQuoteType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function escaperSetHtmlQuoteType(UnitTester $I)
    {
        $I->wantToTest('Escaper - setHtmlQuoteType()');
        $I->skipTest('Need implementation');
    }
}
