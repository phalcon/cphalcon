<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Helper\Db\Connection\SqliteTranslationsFactory;
use Helper\ModelTrait;
use Phalcon\Di;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Language;
use Phalcon\Test\Models\LanguageI18n;
use Phalcon\Mvc\Model\Resultset\Simple;

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
}
