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

namespace Phalcon\Tests\Integration\Mvc\Model\MetaData;

use IntegrationTester;

/**
 * Class GetDataTypesNumericCest
 */
class GetDataTypesNumericCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getDataTypesNumeric()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataGetDataTypesNumeric(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData - getDataTypesNumeric()');
        $I->skipTest('Need implementation');
    }
}
