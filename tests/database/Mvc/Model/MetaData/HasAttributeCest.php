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

namespace Phalcon\Test\Database\Mvc\Model\MetaData;

use DatabaseTester;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

/**
 * Class HasAttributeCest
 */
class HasAttributeCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: hasAttribute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelMetadataHasAttribute(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData - hasAttribute()');

        /** @var MetaData $metadata */
        $metadata = $this->container->get('modelsMetadata');

        $model    = new Invoices();
        $I->assertTrue($metadata->hasAttribute($model, 'inv_id'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_cst_id'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_status_flag'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_title'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_total'));
        $I->assertTrue($metadata->hasAttribute($model, 'inv_created_at'));

        $I->assertFalse($metadata->hasAttribute($model, 'unknown'));
    }
}
