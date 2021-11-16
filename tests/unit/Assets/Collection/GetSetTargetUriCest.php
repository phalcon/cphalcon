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

namespace Phalcon\Tests\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use UnitTester;

/**
 * Class GetSetTargetUriCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetSetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getTargetUri() / setTargetUri()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetTargetUri(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getTargetUri() / setTargetUri()');

        $collection = new Collection();
        $targetUri  = 'dist';
        $collection->setTargetUri($targetUri);

        $I->assertEquals($targetUri, $collection->getTargetUri());
    }
}
