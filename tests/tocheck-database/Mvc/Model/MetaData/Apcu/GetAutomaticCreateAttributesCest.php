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

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Apcu;

use IntegrationTester;

/**
 * Class GetAutomaticCreateAttributesCest
 */
class GetAutomaticCreateAttributesCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Apcu :: getAutomaticCreateAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataApcuGetAutomaticCreateAttributes(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Apcu - getAutomaticCreateAttributes()');
        $I->skipTest('Need implementation');
    }
}
