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

namespace Phalcon\Test\Integration\Mvc\Collection;

use IntegrationTester;

/**
 * Class UnserializeCest
 */
class UnserializeCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: unserialize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionUnserialize(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - unserialize()');
        $I->skipTest('Need implementation');
    }
}
