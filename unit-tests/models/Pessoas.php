<?php

/**
 * Pessoas
 *
 * Pessoas is people in portugais
 */
class Pessoas extends Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'personnes';
	}

	public function columnMap()
	{
		return array(
			'cedula' => 'identificacao',
			'tipo_documento_id' => 'tipoIdentificacao',
			'nombres' => 'nomes',
			'telefono' => 'telefone',
			'direccion' => 'endereco',
			'email' => 'elektroniskPost',
			'fecha_nacimiento' => 'correio',
			'ciudad_id' => 'cidadeId',
			'creado_at' => 'criadoEm',
			'cupo' => 'credito',
			'estado' => 'estado'
		);
	}

}