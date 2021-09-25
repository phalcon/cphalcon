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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Escaper;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Helpers\TagSetup;
use UnitTester;

class GetEscaperServiceCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: getEscaperService()
     *
     * @param UnitTester $I
     *
     * @since  2018-11-13
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function tagGetEscaperService(UnitTester $I)
    {
        $I->wantToTest('Tag - getEscaperService()');

        $escaper = Tag::getEscaperService();
        $I->assertInstanceOf(Escaper::class, $escaper);
        $I->assertInstanceOf(EscaperInterface::class, $escaper);
    }
}
