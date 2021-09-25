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

class GetSetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getTargetUri() / setTargetUri()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetTargetUri(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getTargetUri() / setTargetUri()');

        $collection = new Collection();

        $targetUri = 'dist';

        $collection->setTargetUri($targetUri);

        $I->assertEquals($targetUri, $collection->getTargetUri());
    }
}
