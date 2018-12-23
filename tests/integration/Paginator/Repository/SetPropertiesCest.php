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

namespace Phalcon\Test\Integration\Paginator\Repository;

use IntegrationTester;

/**
 * Class SetPropertiesCest
 */
class SetPropertiesCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: setProperties()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorRepositorySetProperties(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - setProperties()');
        $I->skipTest('Need implementation');
    }
}
