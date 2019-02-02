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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Files;

use IntegrationTester;

/**
 * Class WriteMetaDataIndexCest
 */
class WriteMetaDataIndexCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Files :: writeMetaDataIndex()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataFilesWriteMetaDataIndex(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Files - writeMetaDataIndex()');
        $I->skipTest('Need implementation');
    }
}
