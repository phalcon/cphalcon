<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Models\AlbumORama\Artists;
use Phalcon\Test\Models\Language;
use Phalcon\Test\Models\LanguageI18n;

class RelationsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiSqlite();
    }

    /**
     * Test get related record properly using composite key.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/11755
     */
    public function shouldGetRelationRecordsUsingCompositeKey(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check if tables exist');

        /** @var Language $entity */
        $entity = Language::findFirst();

        $I->assertEquals('Dutch', $entity->lang);
        $I->assertEquals('nl-be', $entity->locale);

        $I->assertInstanceOf(
            Simple::class,
            $entity->translations
        );

        $I->assertInstanceOf(
            Simple::class,
            $entity->getTranslations()
        );

        $I->assertCount(2, $entity->translations);

        $I->assertInstanceOf(
            LanguageI18n::class,
            $entity->translations->getFirst()
        );

        $I->assertEquals(
            'Belgium-1',
            $entity->translations->getFirst()->locale
        );
    }

    public function testRelationshipLoaded(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check if tables exist');

        $hasManyModel = Artists::findFirst();

        $I->assertFalse(
            $hasManyModel->isRelationshipLoaded('albums')
        );

        $hasManyModel->albums;

        $I->assertTrue(
            $hasManyModel->isRelationshipLoaded('albums')
        );

        $belongsToModel = Albums::findFirst();

        $I->assertFalse(
            $belongsToModel->isRelationshipLoaded('artist')
        );

        $belongsToModel->artist;

        $I->assertTrue(
            $belongsToModel->isRelationshipLoaded('artist')
        );
    }
}
