<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

class Pessoas extends Model
{
    public function initialize()
    {
        $this->setSource('personnes');
    }

    public function columnMap()
    {
        return [
            'cedula'            => 'identificacao',
            'tipo_documento_id' => 'tipoIdentificacao',
            'nombres'           => 'nomes',
            'telefono'          => 'telefone',
            'direccion'         => 'endereco',
            'email'             => 'elektroniskPost',
            'fecha_nacimiento'  => 'correio',
            'ciudad_id'         => 'cidadeId',
            'creado_at'         => 'criadoEm',
            'cupo'              => 'credito',
            'estado'            => 'estado',
        ];
    }
}
