<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models;

/**
 * Customers with the related records to save and the validation result set
 * by the test. The public API cannot store a related record that is not an
 * object. Used to test the paths of save() that throw an exception for a
 * related record.
 */
class CustomersRelatedToSave extends Customers
{
    protected bool $failValidation = false;
    protected array $relatedToSave = [];

    public function initialize()
    {
        parent::initialize();

        $this->belongsTo(
            'cst_id',
            Invoices::class,
            'inv_cst_id',
            [
                'alias' => 'invoice',
            ]
        );
    }

    public function setFailValidation(bool $failValidation): void
    {
        $this->failValidation = $failValidation;
    }

    public function setRelatedToSave(array $relatedToSave): void
    {
        $this->relatedToSave = $relatedToSave;
    }

    public function validation(): bool
    {
        return !$this->failValidation;
    }

    protected function collectRelatedToSave(): array
    {
        return $this->relatedToSave;
    }
}
