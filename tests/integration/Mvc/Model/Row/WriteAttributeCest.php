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

namespace Phalcon\Test\Integration\Mvc\Model\Row;

use IntegrationTester;

/**
 * Class WriteAttributeCest
 */
class WriteAttributeCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: writeAttribute()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelRowWriteAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - writeAttribute()');
        $I->skipTest('Need implementation');
    }
}
