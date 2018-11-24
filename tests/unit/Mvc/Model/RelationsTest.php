<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Helper\Db\Connection\SqliteTranslationsFactory;
use Helper\ModelTrait;
use Phalcon\Di;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Language;
use Phalcon\Test\Models\LanguageI18n;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Models\AlbumORama;

class RelationsTest extends UnitTest
{
    use ModelTrait;

    /**
     * Test get related record properly using composite key.
     *
     * @test
     * @issue https://github.com/phalcon/cphalcon/issues/11755
     */
    public function shouldGetRelationRecordsUsingCompositeKey()
    {
        $this->specify(
            'Unable to get related record properly using composite key',
            function () {
                $this->setUpConnectionAwareModelsManager(
                    SqlitetranslationsFactory::class
                );

                /** @var Language $entity */
                $entity = Language::findFirst();

                expect($entity->lang)->equals('Dutch');
                expect($entity->locale)->equals('nl-be');

                expect($entity->translations)->isInstanceOf(Simple::class);
                expect($entity->getTranslations())->isInstanceOf(Simple::class);

                expect($entity->translations)->count(2);

                expect($entity->translations->getFirst())->isInstanceOf(LanguageI18n::class);
                expect($entity->translations->getFirst()->locale)->equals('Belgium-1');
            }
        );
    }

    /**
     * @param string $connection
     * @return \Phalcon\Mvc\Model\Manager
     */
    protected function setUpConnectionAwareModelsManager($connection)
    {
        /** @var \Helper\Db\Connection\AbstractFactory $factory */
        $factory = new $connection();
        $this->setUpModelsManager($factory->createConnection());

        $di = Di::getDefault();

        return $di->getShared('modelsManager');
    }

    public function testRelationshipLoaded()
    {
        $this->specify(
            'Unable to test if "hasMany" relationship exist',
            function () {
                $hasManyModel = AlbumORama\Artists::findFirst();
                expect($hasManyModel->isRelationshipLoaded('albums'))->equals(false);
                $hasManyModel->albums;
                expect($hasManyModel->isRelationshipLoaded('albums'))->equals(true);
            }
        );

        $this->specify(
            'Unable to test if "belongsTo" relationship exist',
            function () {
                
                $belongsToModel = AlbumORama\Albums::findFirst();
                expect($belongsToModel->isRelationshipLoaded('artist'))->equals(false);
                $belongsToModel->artist;
                expect($belongsToModel->isRelationshipLoaded('artist'))->equals(true);
            }
        );
    }
}
