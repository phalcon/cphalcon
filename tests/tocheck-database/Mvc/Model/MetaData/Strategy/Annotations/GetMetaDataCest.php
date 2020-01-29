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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Strategy\Annotations;

use IntegrationTester;

/**
 * Class GetMetaDataCest
 */
class GetMetaDataCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Strategy\Annotations :: getMetaData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataStrategyAnnotationsGetMetaData(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Strategy\Annotations - getMetaData()');
        $I->skipTest('Need implementation');
    }
}
